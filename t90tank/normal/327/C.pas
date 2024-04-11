const
   maxn = 200000;
   maxp = 1000000007;
 var
   s : ansistring;
   n,k,i,cck,ans,tmp : longint;
   cc : array[0..maxn] of longint;

   procedure Init;
   var i : longint;
   begin
     readln( s );  n := length( s );
     readln( k );
     cc[0] := 1;
     for i := 1 to n do cc[i] := cc[i-1] shl 1 mod maxp;
     cck := cc[n];
   end;

   function Count( k : longint; var mul : longint  ) : longint;
   var t,ans : longint;
   begin
     if k = 0 then
     begin mul := cck; exit( 1 ); end;
     t := Count( (k-1) shr 1 , mul );
     ans := (int64(mul)+1)*t mod maxp;
     mul := int64(mul)*mul mod maxp;
     if not odd( k ) then
     begin
       mul := int64(mul)*cck mod maxp;
       ans := (int64(ans)*cck+1) mod maxp;
      end;
      exit( ans );
   end;

 begin
   Init;
   ans := 0;
   for i := 1 to n do
     if s[i] in ['0','5'] then
       ans := ( ans + int64(cc[i-1])*Count(k-1,tmp) mod maxp ) mod maxp;
   writeln( ans );
 end.