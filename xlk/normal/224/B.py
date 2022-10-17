n,k=map(int,raw_input().split())
a=map(int,raw_input().split());
if len(set(a))<k:
	print -1,-1
else:
	v=[0]*100020
	i=j=c=0
	while c<k:
		if v[a[j]]==0:
			c+=1
		v[a[j]]+=1;
		j+=1
	while v[a[i]]>1:
		v[a[i]]-=1
		i+=1
	print i+1,j