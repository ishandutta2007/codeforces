n=[int(k) for k in raw_input().split(" ")][0]
a=[int(k) for k in raw_input().split(" ")]

mc=10000000
good=-1
for i in range(1,101):
    res=0
    for j in a:
        res+=max(0,abs(j-i)-1)
    if res<mc:
        mc=res
        good=i

print good,mc