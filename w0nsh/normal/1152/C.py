from math import gcd
a, b = map(int, input().split())
if a > b:
	a, b = b, a
divs = []
i = 1
while i*i <= b-a:
	if (b-a)%i == 0:
		divs.append(i)
		if i*i != b-a:
			divs.append((b-a)//i)
	i += 1
best = (a*b//gcd(a, b), 0)
for d in divs:
	rest = a%d
	if rest == 0:
		rest = d
	ths = d - rest
	if ths < 0:
		continue
	cand = ((a+ths)*(b+ths)//gcd(a+ths, b-a), ths)
	# print(d, ths, cand)
	if cand[0] < best[0]:
		best = cand
	elif cand[0] == best[0] and cand[1] < best[1]:
		best = cand
print(best[1])