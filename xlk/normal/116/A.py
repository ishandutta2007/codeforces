n=input()
z=s=0
for i in range(n):
	s-=eval(raw_input().replace(' ','-'))
	z=max(z,s)
print z