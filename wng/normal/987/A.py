#[int(k) for k in raw_input().split(" ")]
d={"purple":"Power",
	"green":"Time",
	"blue":"Space",
	"orange":"Soul",
	"red":"Reality",
	"yellow":"Mind"}
	
n=int(raw_input())

for i in  range(n):
	s=raw_input()
	del d[s]

print len(d)
for v in d.values():
	print v