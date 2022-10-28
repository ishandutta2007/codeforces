k = int(input())
l = [1]
m = 10**9+7
for i in range(k-1):
	l.append((16*l[-1]**2)%m)
print(6*l[-1]%m)