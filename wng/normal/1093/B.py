n=[int(k) for k in raw_input().split(" ")][0]
for i in range(n):
    s=sorted(raw_input())
    if s[0]==s[-1]:
        print -1
    else:
        print "".join(s)