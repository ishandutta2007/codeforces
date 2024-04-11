import sys
flush = sys.stdout.flush
N = int(input())
x = []
for i in range(2,N+1):
    print("? {} {}".format(1,i))
    flush()
    x.append(int(input()))
print("? {} {}".format(2,3))
x.append(int(input()))
flush()
ans = []
for i in range(N-2):
    ans.append(x[N-2-i]-x[N-3-i])
ans.append(x[N-1]-ans[-1])
ans.append(x[0]-ans[-1])
ans = ans[::-1]
ans = ["!"]+ans
print(*ans,flush=True)