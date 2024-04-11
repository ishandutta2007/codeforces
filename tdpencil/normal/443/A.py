g=input()
nums=[]

letters="abcdefghijklmnopqrstuvwxyz"
for i in g:
	if i in letters:
		nums.append(i)
Mxn=set(nums)
print(len(Mxn))