n, m = (int(x) for x in raw_input().split())
elem = [int(x) for x in raw_input().split()]
elem.append(-1000000000000)
elem.append(1000000000000)
elem = sorted(elem)

def solve(curr):
	l = 0;
	r = len(elem)-1
	while l < r:
		m = (l+r)/2
		if elem[m] <= curr:
			l = m+1
		else:
			r = m
	return str(l-1)

print " ".join([solve(int(x)) for x in raw_input().split()])