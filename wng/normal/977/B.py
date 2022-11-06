n=int(raw_input())
s=raw_input()
d={}
for k in range(n-1):
	a="".join([s[k],s[k+1]])
	if a not in d:
		d[a]=0
	d[a]+=1

print [k for k in d if d[k]==max(d.values())][0]