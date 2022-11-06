n,m=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]

for k in sorted(a)[::-1]:
    if m%k==0:
        print m/k
        break