l,r = [int(i) for i in raw_input().split()]
cnt = 0
for i in range(l,r+1):
	if len(set(list(str(i)))) == len(str(i)):
		print i
		exit()
print -1