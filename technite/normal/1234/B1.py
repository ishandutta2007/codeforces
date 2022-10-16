x, y = [int(x) for x in input("").split()] 
L = list(map(int, input("").split())) 
l=[]
for i in L:
	if(len(l)<y):
		if i not in l:
			l.insert(0,i)
	elif(len(l)==y):
		if i not in l:
			l.insert(0,i)
			l.pop()
print(len(l))
for i in l:
	print(i,end=" ")