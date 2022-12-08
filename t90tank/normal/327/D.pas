const
  maxn = 510;
  key : array[1..4,1..2] of longint = ((1,0),(0,1),(0,-1),(-1,0));
type
  point = record
            x,y : longint;
          end;
var
  n,m,tot : longint;
  c : array[0..maxn,0..maxn] of longint;
  g : array[0..maxn,0..maxn,1..4] of boolean;
  a : array[0..maxn,0..maxn] of char;
  q : array[0..maxn*maxn] of point;
  v : array[0..maxn,0..maxn] of boolean;
  wr : array[0..1000000] of ansistring;

  procedure pr( a : ansistring; x : longint; b : ansistring; y : longint );
  var s1,s2 : ansistring;
  begin
    str( x,s1 ); str( y,s2 );
    inc( tot ); wr[tot] := a+s1+b+s2;
  end;

  procedure Init;
  var i,j,k : longint;
  begin
    readln( n , m );
    for i := 0 to n + 1 do
      for j := 0 to m + 1 do
        a[i,j] := '#';
    for i := 1 to n do
    begin
      for j := 1 to m do read( a[i,j] );
      readln;
    end;
    tot := 0;
//    fillchar( c , sizeof( c ) , 255 );
//    fillchar( v , sizeof( v ) , true );
    fillchar( g , sizeof( g ) , false );
//    for i := 1 to n do
//      for j := 1 to m do
//        if a[i,j] <> '#' then
//        begin
//          inc( c[i,j] );
  //        for k := 1 to 2 do
//            if ( v[i+key[k,1],j+key[k,2]] ) and ( a[i+key[k,1],j+key[k,2]] <> '#' ) then
//            begin
//              g[i,j,k] := true; g[i+key[k,1],j+key[k,2],5-k] := true;
//              inc( c[i,j] ); inc( c[i+key[k,1],j+key[k,2]] ); v[i+key[k,1],j+key[k,2]] := false;
//        end;
    for i := 1 to n do
      for j := 1 to m do
        if a[i,j] <> '#' then pr( 'B ' , i , ' ' , j );
  end;

  procedure Main;
  var h,t,i,j,k : longint;
  begin
    fillchar( c , sizeof( c ) , 255 );
    for j := 1 to n do
      for k := 1 to m do
        if ( c[j,k] = -1 ) and ( a[j,k] <> '#' ) then
        begin
          h := 0; t := 1;
          q[t].x := j; q[t].y := k;
          c[j,k] := 0;
          while h < t do
          begin
            inc( h );
            with q[h] do
              for i := 1 to 4 do
                if ( c[x+key[i,1],y+key[i,2]] = -1 ) and ( a[x+key[i,1],y+key[i,2]] <> '#' ) then
                begin
                  g[x,y,i] := true; g[x+key[i,1],y+key[i,2],5-i] := true;
                  inc( t ); q[t].x := x+key[i,1]; q[t].y := y+key[i,2];
                  c[q[t].x,q[t].y] := 0;
                end;
          end;
        end;
    for i := 1 to n do
      for j := 1 to m do
        if a[i,j] <> '#' then
          for k := 1 to 4 do
            if g[i,j,k] then inc( c[i,j] );{
    for i := 1 to n do
    begin
      for j := 1 to m do
        write( c[i,j] , ' ' );
      writeln;
    end;}
    h := 0; t := 0;
    for i := 1 to n do
      for j := 1 to m do
        if c[i,j] = 1 then
        begin inc( t ); q[t].x := i; q[t].y := j; end;
    while h < t do
    begin
      inc( h );
      with q[h] do
        if c[x,y] = 1 then
        begin
          pr( 'D ',x,' ',y );
          pr( 'R ',x,' ',y );
          dec( c[x,y] );
          for i := 1 to 4 do
            if g[x,y,i] then
            begin
              dec( c[x+key[i,1],y+key[i,2]] );
              if c[x+key[i,1],y+key[i,2]] = 1 then
              begin inc( t ); q[t].x := x+key[i,1]; q[t].y := y+key[i,2]; end;
            end;
        end
        else continue;
    end;
  end;

begin
  Init;
  Main;
  writeln( tot );
  for n := 1 to tot do writeln( wr[n] );
end.