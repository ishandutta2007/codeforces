n,k=[int(k) for k in raw_input().split(" ")]

r1=k/2
r2=k-r1

res=["."*n]

for i in [r1,r2]:
    rr=""
    if i%2:
        rr+="."*((n-i)/2)+"#"*i+"."*((n-i)/2)
    else:
        rr+="."+"#"*(i/2)+"."*(n-2-i)+"#"*(i/2)+"."
    res+=[rr]


res+=["."*n]

print "YES"
for k in res:
    print k