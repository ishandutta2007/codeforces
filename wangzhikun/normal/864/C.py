l = [int(i) for i in raw_input().split(' ')]
ans = 0
curf = l[1]-l[2]
if curf<0:
    print -1
    exit()
for i in range(l[3]-1):
	req = (l[0]-l[2])*2*((i+1)%2)+l[2]*2*(i%2)
	if curf<req:
		curf=l[1]
		ans+=1
	curf-=req
	if curf<0:
		print -1
		exit()
if (l[3]%2 == 0 and curf<l[2]) or (l[3]%2 == 1 and curf<l[0]-l[2]) and ans!=-1:
	ans+=1
if (l[3]%2 == 0 and l[1]<l[2]) or (l[3]%2 == 1 and l[1]<l[0]-l[2]):
    print -1
    exit()
print ans