n,a=input(),map(int,raw_input().split())
a=[sum(a[i::3])for i in [0,1,2]]
print["chest","biceps","back"][a.index(max(a))]