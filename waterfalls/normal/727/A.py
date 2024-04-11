a,b = map(int,input().split())
order = [b]
while order[-1]>a:
	if order[-1]%2==0:
		order.append(order[-1]//2)
	elif order[-1]%10==1:
		order.append(order[-1]//10)
	else:
		order.append(0)
if order[-1]==a:
	print("YES")
	print(len(order))
	print(' '.join(map(str,order[::-1])))
else:
	print("NO")