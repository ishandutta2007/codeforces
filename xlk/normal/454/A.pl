#!perl -p
$a=$_="D"x$_;while(/DD/){s/\bD|D\b/*/g;$a="$_\n$a\n$_"}$_=$a