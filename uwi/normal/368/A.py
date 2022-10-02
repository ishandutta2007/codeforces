n,d = map(int, raw_input().split(" "))
a = [int(x) for x in raw_input().split(" ")]
m = input()

a.sort()
ret = 0
if m > n:
	ret -= d * (m - n)
ret += sum(a[:min(m,n)])
print ret