from math import gcd

def lcm(a,b):
	return a*b//gcd(a,b)

def mod(a,m):
	a%=m
	if a<0:
		a+=m
	return a

n,k=map(int, input().split())
a,b=map(int, input().split())
st,ed=[],[]
nk=n*k

for i in range(0,n):
	st.append(mod(i*k-a,nk))
	st.append(mod(i*k+a,nk))
	ed.append(mod(i*k-b,nk))
	ed.append(mod(i*k+b,nk))

mn=100000000000000000
mx=-100000000000000000
sz=len(ed)

for i in range(0,2):
	for j in range(0,sz):
		jp=ed[j]-st[i]
		if ed[j]<st[i]:
			jp+=nk
		if jp==0:
			jp+=nk
		lm=lcm(jp,nk)//jp
		mn=min(mn,lm)
		mx=max(mx,lm)

print(mn,mx)