#!/bin/python3
# Not sure why people get so many failed submissions.  Numerical error?

from fractions import Fraction
for _ in range(int(input())):
	hot, cold, temp=map(int, input().split())
	if temp>=hot: print(1); continue
	if temp*2<=hot+cold: print(2); continue

	x=int(1/((temp-Fraction(hot+cold)/2)/(hot-cold))/2)
	if x<1: x=1
	if x%2==0: x-=1
	print(min((x, x+2),
		key=lambda x: abs(Fraction(hot+cold)/2+Fraction(hot-cold)/(2*x)-temp))
		)