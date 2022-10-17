a=map(int,raw_input().split())
print max(0,min(a[:4]+[a[-1]+1])-a[-2])