a=$<.read.split.drop(1).sort!
n=a.size
if a.uniq.size==2 and n%2==0 and a[n/2]!=a[n/2-1]
	puts :YES,a[0],a[-1]
else
	puts :NO
end