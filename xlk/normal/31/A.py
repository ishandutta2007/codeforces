n=input()
a=map(int,raw_input().split())
for i in range(n):
	for j in range(i):
		if a[i]+a[j] in a:
			print a.index(a[i]+a[j])+1,i+1,j+1
			exit()
print -1