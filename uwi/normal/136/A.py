import sys

n = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().strip().split()]
ia = [0]*n
for i,v in enumerate(a):
        ia[v-1] = i
print " ".join([str(x+1) for x in ia])