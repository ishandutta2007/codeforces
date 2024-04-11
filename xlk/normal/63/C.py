v=['%04d'%t for t in range(9876)if len(set('%04d'%t))==4]
for _ in range(int(input())):
	a,b,c=input().split()
	b=int(b)
	c=int(c)
	v=[u for u in v if len(set(u)&set(a))==b+c and sum(u[i]==a[i]for i in range(4))==b]
print(v[0]if len(v)==1 else['Incorrect data','Need more data'][len(v)>0])