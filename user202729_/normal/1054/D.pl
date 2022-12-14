#!/bin/perl
($n,$k)=split' ',<>;
@a=split' ',<>;
@a[$_]=@a[$_]^0+@a[$_-1] for(1..$#a);
push @a,0;
for(@a){
	$_=$_^~(-1<<$k) if 0==($_&1<<($k-1))
}
@a=sort @a;
$le=0;  #lastend
$ans=0;
for(1..+@a){
	if (@a[$_]!=@a[$_-1]) {
		$sz=$_-$le;
		$s1=int $sz/2;
		$s2=$sz-$s1;
		$ans+=($s1*($s1-1)+$s2*($s2-1))/2;
		$le=$_;
	}
}
print $n*($n+1)/2-$ans,"\n";