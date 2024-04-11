n, k = (int(x) for x in raw_input().rstrip().split())
ret = 10 ** (n-1)
cap = 10 ** n
while ret <= 0 or ret % k != 0:
	ret += 1
if ret >= cap:
	ret = -1
print ret