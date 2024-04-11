n = int(input())
def find(n):
	seen ={}
	lst = []
	for i in range(n):
		j = int(input())
		lst.append(j)
	newlst = []
	for i in lst:
		if i not in seen:
			newlst.append(i)
			seen[i] = True
	if len(newlst) != 2:
		print("NO")
		return
	count1 =0
	count2 = 0
	for i in newlst:
		for j in lst:
			if i == j and i == newlst[0]:
				count1+=1
			elif i == j:
				count2+=1
	if count1 != count2:
		print("NO")
		return
	print("YES")
	for i in newlst:
		print(i, end=" ")
	return
find(n)