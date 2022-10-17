n=input()
c=[0]*10
a=map(int,raw_input().split())
for i in a:
	c[len(str(i))-1]+=1
z=0
for i in a:
	for j in range(10):
		z+=10*i*c[j]
		t=10*100**j
		i=i/t*10*t+i%t
		z+=i*c[j]
print z%998244353