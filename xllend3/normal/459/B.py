import sys
n=input()
a=map(int,raw_input().split())
Max,Min,cnt1,cnt2=0,int(1e9),0,0
for i in range(n):
	if a[i]>Max:
		Max=a[i]
	if a[i]<Min:
		Min=a[i]
for i in range(n):
	if a[i]==Max:
		cnt1+=1
	if a[i]==Min:
		cnt2+=1
if Max-Min>0:
	print Max-Min,cnt1*cnt2
else:
	print 0,cnt1*(cnt1-1)/2