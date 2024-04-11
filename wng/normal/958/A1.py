#[int(k) for k in raw_input().split(" ")]

n=int(raw_input())

t1=[]
for k in range(n):
	t1+=[[1 if k=="X" else 0 for k in raw_input()]]
t2=[]
for k in range(n):
	t2+=[[1 if k=="X" else 0 for k in raw_input()]]


def rot(flip,idr,t):
	tt=[]
	for i in range(n):
		for j in range(n):
			ii=i
			jj=j
			if flip:
				ii=n-1-ii
			if idr:
				if idr==1:
					ii,jj=n-1-jj,ii
				if idr==2:
					ii,jj=n-1-ii,n-1-jj
				if idr==3:
					ii,jj=jj,n-1-ii
			tt+=[t[ii][jj]]
#	print flip,idr,tt
	return tuple(tt)
	

def test(t1,t2):
	tc=rot(0,0,t1)
	for flip in range(2):
		for r in range(4):
			ot=rot(flip,r,t2)
			if ot==tc:
				return "Yes"
	return "No"

print test(t1,t2)