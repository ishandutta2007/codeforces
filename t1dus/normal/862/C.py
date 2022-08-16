def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
   
from random import randint    

n,x = map_input()
if n == 2 and x == 0:
	print("NO")
else:	
	while True:
		s = set([])
		a = []
		cnt = 0
		for i in range(n-1):
			while True:
				cur = randint(0,500001)
				if cur not in s:
					s.add(cur)
					a.append(cur)
					cnt ^= cur
					break
		cnt ^= x			
		if cnt in s:
			continue
		else:
			print("YES")
			for i in a:
				print(i,end=' ')
			print(cnt)
			break