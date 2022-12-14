n=int(input())
x=set(input().split()[1:])
for _ in range(n-1):
	x&=set(input().split()[1:])
print(' '.join(x))