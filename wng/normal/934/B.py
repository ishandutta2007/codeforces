#[int(k) for k in raw_input().split(" ")]

k=int(raw_input())

loops=[1,0,0,0,1,0,1,0,2,1]

if k>36:
    print "-1"
else:
    nb8=k/2
    left=k%2
    print "8"*nb8+left*"4"+"1"*(18-nb8-left)