n=input()
z=0
for i in range(n):
	a=map(int,raw_input().split())
	if sum(a)>=2:
		z+=1
print z