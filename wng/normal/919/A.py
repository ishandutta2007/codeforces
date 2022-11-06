n,m=[int(k) for k in raw_input().split(" ")]

minres=100000000
for i in range(n):
    x,y=[float(k) for k in raw_input().split(" ")]
    minres=min(minres,m*x/y)

print "{:.8f}".format(minres)