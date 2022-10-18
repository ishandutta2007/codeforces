//NOT MY CODE
const   fi='';
        nmax=5*100000;
type    data=longint;
var
        f:text;
        A,dem:array[0..nmax+1] of int64;
        n:data; res:int64;
 
procedure docfile;
var
        i,j:data;
        x:int64;
begin
        assign(f,fi); reset(f);
        readln(f,n);
        a[0]:=0;
        for i:=1 to n do
                begin
                        read(f,x);
                        a[i]:=a[i-1]+x;
                end;
        close(f);
end;
 
procedure xuli;
var     i,j:data;
        dem:int64;
begin
        res:=0; dem:=0;
        if a[n] mod 3 <>0 then exit;
        for i:=n-1 downto 1 do
                begin
                if a[n] div 3 = a[i] then
                        inc(res,dem);
                if (a[n] div 3)*2 = a[i] then
                        inc(dem)
                end;
 
end;
 
begin
        docfile;
        xuli;
        writeln(res);
end.