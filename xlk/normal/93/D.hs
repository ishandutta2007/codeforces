main=do
	[l,r]<-scan
	print $ (g(r)-g(l-1))`mod`p
	where
		scan=fmap(map read.words)getLine
		p=1000000007
		sqr x=x*x`mod`p
		pw::Integer->Integer->Integer
		pw x y
			| y==0=1
			| mod y 2==1=x*(pw x $y-1)`mod`p
			| mod y 2==0=sqr(pw x $y`div`2)`mod`p
		s::Integer->Integer
		s x
			| x==0=0
			| x==1=4
			| mod x 2==1=11*(pw 3 $x`div`2)-7
			| otherwise=19*(pw 3 $x`div`2-1)-7
		g x=(s(x)+s((x+1)`div`2))*(pw 2 $p-2)`mod`p