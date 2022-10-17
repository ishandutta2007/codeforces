main=do
	[n,m,a]<-fmap(map read.words)getLine
	print $((n+a-1)`div`a)*((m+a-1)`div`a)