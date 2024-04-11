input()
print ['NO','YES'][sum(map(int,raw_input().split()))<=sum(sorted(map(int,raw_input().split()))[-2:])]