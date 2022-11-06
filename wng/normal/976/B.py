n,m,k=[int(k) for k in raw_input().split(" ")]

if k<n:
    print k+1,1
else:
    k-=n
    nbhigh=k/(m-1)
    nbside=k%(m-1)
    sens=nbhigh%2
    print  n-nbhigh,( (2+nbside) if not sens else (m- nbside))