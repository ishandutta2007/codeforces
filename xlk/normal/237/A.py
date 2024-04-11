n=input()
a=[0]*9999
for i in range(n):
	x,y=map(int,raw_input().split())
	a[60*x+y]+=1;
print max(a)