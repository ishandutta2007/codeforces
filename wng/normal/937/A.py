n=int(raw_input())

a=[int(k) for k in raw_input().split(" ")]

sa=set(a)

if 0 in sa:
    print len(sa)-1
else:
    print len(sa)