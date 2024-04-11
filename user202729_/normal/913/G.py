import sys
import random

N = 40

ntest = int(sys.stdin.readline())
for _ in range(ntest):

	target = int(sys.stdin.readline())
	# target = random.randint(1, 10 ** 11 - 1)
	
	# savetarget = target

	divtarget = 2 ** N
	target_min = target
	target_max = target + 1
	while True:
	
		target_min *= 10
		target_max *= 10
		
		if target_min // divtarget == (target_max - 1) // divtarget:
			# assert target_max - target_min < 3 * divtarget
			continue
			
		target = (target_max - 1) // divtarget
		if target % 5 == 0:
			target -= 1
		# assert target % 5 != 0
		target *= divtarget
		# assert target % divtarget == 0
		if target >= target_min: 
			break
	
	# print(target)

	# del target_max
	# del target_min
	# del divtarget

	mod = 10 ** 0
	base = N
	gap = 1

	for i in range(100):
		# print(pow(2, base, mod));
		
		mod *= 10
		target_mod = target % mod
		
		# assert mod == 10 ** (1+i)
		# assert target_mod % (2 ** (1+i)) == 0
		
		# print('>>>', target_mod)
		cur = pow(2, base, mod)
		cur_mul = pow(2, gap, mod)
		while cur != target_mod:
			# print(pow(2, base, mod));
			base += gap
			cur = (cur * cur_mul) % mod
			
		newgap = gap
		base += gap
		cur = pow(2, base, mod)
		while cur != target_mod:
			# print(pow(2, base, mod));
			base += gap
			newgap += gap
			cur = (cur * cur_mul) % mod
			
		# assert pow(2, base + newgap, mod) == target_mod
			
		gap = newgap

		if mod > target: break
		
	print(base)
	
	# debug below
	# a = str(savetarget)
	# b = str(pow(2, base, mod))
	# print(b)
	# assert b[:len(a)] == a, (b[:len(a)], a)
	# print(10 ** 50)