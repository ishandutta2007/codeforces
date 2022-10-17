n = int(input())
lst = [int(i) for i in input().split(' ')]
curi = -1
ans = [n]
while(lst[curi] != 1):
	ans.append(lst[curi])
	curi = lst[curi] - 2
ans.append(1)
ans = ans[::-1]
for i in ans:
	print(i,end = ' ')