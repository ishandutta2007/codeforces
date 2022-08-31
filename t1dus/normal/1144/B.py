n = int(input())
a = list(map(int,input().split()))
odd = []
even = []
for i in a:
	if i%2 == 0:
		even.append(i)
	else:
		odd.append(i)
x = len(odd)
y = len(even)
odd.sort()
even.sort()
if x == y:
	print(0)
elif x < y:
	y -= x
	y -= 1
	ans = 0
	for i in range(y):
		ans += even[i]
	print(ans)	
else:
	x -= y
	x -= 1
	ans = 0
	for i in range(x):
		ans += odd[i]	 				
	print(ans)