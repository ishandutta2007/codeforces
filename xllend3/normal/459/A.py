import sys
a,b,c,d=map(int,raw_input().split())
if a==c:
    print a+d-b,b,a+d-b,d
    sys.exit(0)
if b==d:
    print a,b+c-a,c,d+c-a
    sys.exit(0)
if c-a==d-b:
    print c,b,a,d
    sys.exit(0)
if a-c==d-b:
    print c,b,a,d
    sys.exit(0)
print "-1"