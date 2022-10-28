I = lambda:int(input())
n = I()
sml = 0
big = 5000000
while big - sml > 1:
	mid = (big + sml) // 2
	print('?', mid)
	x = I()
	if x != 1:
		sml = mid
	else:
		big = mid
 
best = big
for i in range(2, n + 1):
	print('?', big // i)
	x = I()
	if x > 0:
		best = min(best, x * (big // i))
print('!', best)