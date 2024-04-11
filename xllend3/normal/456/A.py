import sys
for i in range(input()):
    a,b=map(int,raw_input().split())
    if a<b:
        print 'Happy Alex'
        sys.exit(0)
print 'Poor Alex'