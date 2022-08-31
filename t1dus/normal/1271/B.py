n = int(input())
s = input()
b = 0
w = 0
for i in s:
	if i == 'W':w+=1
	else:b+=1
if w%2 and b%2:
	print(-1)
elif w%2:
	a = [i for i in s]
	ans = []
	for i in range(n):
		if a[i] != 'W':
			ans.append(i+1)
			if(a[i+1] == 'W'): a[i+1] = 'B'
			else: a[i+1] = 'W'
	print(len(ans))
	for i in ans: print(i,end=' ')
	print()
else:
	a = [i for i in s]
	ans = []
	for i in range(n):
		if a[i] != 'B':
			ans.append(i+1)
			if(a[i+1] == 'W'): a[i+1] = 'B'
			else: a[i+1] = 'W'
	print(len(ans))
	for i in ans: print(i,end=' ')
	print()