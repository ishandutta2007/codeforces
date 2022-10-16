b, k = map(int, input().split())

v = list(map(int, input().split()))

parity = 0
if b & 1:
	for i in v:
		parity = (parity + i) % 2
else:
	parity = v[-1] % 2

if parity:
	print("odd")
else:
	print("even")