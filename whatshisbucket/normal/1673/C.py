M=10**9+7
m=40001
r=range
v=[1]+[0]*m
for i in r(1,m):
	if str(i)==str(i)[::-1]:
		for j in r(i,m):v[j]=(v[j]+v[j-i])%M
for _ in r(int(input())):print(v[int(input())])