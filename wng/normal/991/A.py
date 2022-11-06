a,b,c,n=[int(k) for k in raw_input().split(" ")]

nok=a+b-c
if nok>=n or min(a,b)<c:
    print -1
else:
    print n-nok