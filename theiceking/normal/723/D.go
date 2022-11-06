package main
import (
	. "fmt"
	"bufio"
	"os"
	"sort"
)

type Triple struct {
    sz int
    coord_x int
    coord_y int
}

var x []int = []int{-1, 1, 0, 0}
var y []int = []int{0, 0, -1, 1} 
var grid [][]byte
var vis [][]bool
	
var n, m, k int

func run (i, j int) (tot int, ocean bool) {
    if i < 1 || j < 1 || i > n || j > m {
        return 0, true
    }
    if vis[i][j] || grid[i][j] != '.' {
        return 0, false
    }
    vis[i][j] = true
    tot = 1

    for cur := 0; cur < 4; cur ++ {
        amount, oce := run (i + x[cur], j + y[cur])
        tot += amount 
        if oce {
            ocean = true
        }
    }
    return
}

func fill (i, j int) {
    if i < 1 || j < 1 || i > n || j > m || grid[i][j] != '.' {
        return
    }
    grid[i][j] = '*'
    for cur := 0; cur < 4; cur ++ {
        fill (i + x[cur], j + y[cur])
    }
}

func main(){
	read := bufio.NewReader(os.Stdin)
	write := bufio.NewWriter(os.Stdout)
	
	defer write.Flush()
    
    Fscanf(read, "%d %d %d\n", &n, &m, &k)
    
    grid, vis = make ([][]byte, n + 20), make ([][]bool, n + 20)
    
	for i := 1; i <= n; i ++ {
	    grid[i], vis[i] = make ([]byte, m + 20), make ([]bool, m + 20)
	    
	    for j := 1; j <= m; j ++ {
	        Fscanf (read, "%c", &grid[i][j])
	    }
	    Fscanf (read, "\n")
	}
	
	sz := []Triple{}
	
	for i := 1; i <= n; i ++ {
	    for j := 1; j <= m; j ++ {
	        if !vis[i][j] {
	            tot_amount, ocean := run (i, j)
	            if !ocean {
	                sz = append(sz, Triple{tot_amount, i, j})
	            }
	        }
	    }
	}

	ans := 0
	sort.Slice(sz, func (a, b int) bool {
	    return sz[a].sz < sz[b].sz
	})
	
	for i := 0; i < len(sz) - k; i ++ {
	    ans += sz[i].sz
	    fill (sz[i].coord_x, sz[i].coord_y)
	}
	
	Fprintln(write, ans)
	for i := 1; i <= n; i++ {
	    for j := 1; j <= m; j++ {
	        Fprintf(write, "%c", grid[i][j])
	    }
	    Fprintf(write, "\n")
	}
}