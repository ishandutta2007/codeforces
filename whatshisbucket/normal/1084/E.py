u=input;n,k=map(int,u().split());s,t,d,a=u(),u(),1,0
for i in range(n):
	d*=2
	if s[i]=="b":d-=1
	if t[i]=="a":d-=1
	if d>k:a+=(n-i)*k;break
	a+=d
print(a)