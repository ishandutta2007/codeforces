#n=int(raw_input())
n,k,m=[int(ii) for ii in raw_input().split(" ")]
a=[int(ii) for ii in raw_input().split(" ")]

tiroirs={}
isok=False
for i in a:
    mod=i%m
    if mod not in tiroirs:
        tiroirs[mod]=[]
    tiroirs[mod]+=[i]
    if len(tiroirs[mod])==k:
        print "Yes"
        print " ".join([str(j) for j in tiroirs[mod]])
        isok=True
        break

if not isok:
    print "No"