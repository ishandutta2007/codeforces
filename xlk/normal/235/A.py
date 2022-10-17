def gcd(x,y):
	return gcd(y,x%y) if y else x
def lcm(x,y):
	return x/gcd(x,y)*y;
n=input()
z=0
for i in range(max(n-30,1),n+1):
	for j in range(max(n-30,1),n+1):
		for k in range(max(n-30,1),n+1):
			z=max(z,lcm(i,lcm(j,k)))
print z